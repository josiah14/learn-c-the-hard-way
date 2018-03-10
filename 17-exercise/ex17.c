#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Address {
  int id;
  int set;
  char* name;
  char* email;
};

struct Database {
  int max_data;
  int max_rows;
  struct Address* rows;
};

struct Connection {
  FILE* file;
  struct Database* db;
};

void Database_close(struct Connection* conn) {
  if (conn) {
    if (conn->file) {
      fclose(conn->file);
    }
    if (conn->db) {
      free(conn->db);
    }
    free(conn);
  }
}

void die(const char* message, struct Connection* conn) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  Database_close(conn);

  exit(1);
}

void Address_print(struct Address* addr) {
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection* conn) {
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) {
    die("Failed to load the database.", conn);
  }
}

struct Connection* Database_open(const char* filename, char mode, long max_rows, long max_data) {
  struct Connection* conn = malloc(sizeof(struct Connection));
  if (!conn) die("Memory error", conn);

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db) die("Memory error", conn);

  conn->db->max_rows = max_rows;
  conn->db->max_data = max_data;
  // TODO: Dude, set the number of rows before this, bro!
  conn->db->rows = malloc(sizeof(struct Address) * conn->db->max_rows);
  if (!conn->db->rows) die("Memory error", conn);

  if (mode == 'c') {
    // open the file for writing only
    // Since we aren't checking to see if the file exists, we must be creating
    // it, here.  Otherwise, we would need to load it, as below
    conn->file = fopen(filename, "r+");
  } else {
    // open the file for both reading and writing
    conn->file = fopen(filename, "r+");
    if (conn->file) {
      Database_load(conn);
    }
  }

  if (!conn->file) {
    die("Failed to open the file.", conn);
  }

  return conn;
}

void Database_write(struct Connection* conn) {
  // make sure we are at the beginning of the file, first
  if (conn->file == NULL) {
    printf("file pointer is null\n");
  } else {
    printf("file pointer is NOT null\n");
  }
  rewind(conn->file);
  /* rewind(conn->file); // TODO: This breaks... */
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) {
    die("Failed to write to database.", conn);
  }

  rc = fflush(conn->file);
  if (rc == -1) {
    die("Could not flush the database.", conn);
  }
}

void Database_create(struct Connection *conn) {
  int i = 0;

  for (i = 0; i < conn->db->max_rows; i++) {
    // make a prototype to initialize it
    struct Address addr = { .id = i, .set = 0 };
    // then, just assign it
    // TODO this assignment below breaks.
    conn->db->rows[i] = addr;
  }
}

void Database_set(struct Connection* conn,
                  int id,
                  const char *name,
                  const char *email) {
  /* struct Address* addr = &conn->db->rows[id]; */
  struct Address* addr = malloc(sizeof(struct Address));
  // TODO fix the bug in the line below - causes a segmentation fault
  conn->db->rows[id] = *addr;
  if (addr->set) {
    die("Database address already set.  You must delete it before you can set it, again.", conn);
  }

  addr->set = 1;
  // TODO: WARNING: bug, read the "How To Break It" and fix this
  *addr->name = '\0';
  char* res = strncat(addr->name, name, conn->db->max_data - 1);
  // demonstrate the strncpy bug
  if (!res) {
    die("Name copy failed", conn);
  }

  *addr->email = '\0';
  res = strncat(addr->email, email, conn->db->max_data - 1);
  if (!res) {
    die("Email copy failed", conn);
  }
}

void Database_get(struct Connection* conn, int id) {
  struct Address* addr = &conn->db->rows[id];

  if (addr->set) {
    Address_print(addr);
  } else {
    die("ID is not set", conn);
  }
}

void Database_delete(struct Connection* conn, int id) {
  struct Address addr = { .id = id, .set = 0 };
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection* conn) {
  int i = 0;
  struct Database* db = conn->db;

  for (i = 0; i < conn->db->max_rows; i++) {
    struct Address* cur = &db->rows[i];

    if (cur->set) {
      Address_print(cur);
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc < 5) {
    die("USAGE: ex177 <dbfile> <max_rows> <max_data> <action> [action params]", NULL);
  }

  char* filename = argv[1];
  char action = argv[4][0];
  int max_rows = atoi(argv[2]);
  int max_data = atoi(argv[3]);
  printf("world!\n");
  struct Connection* conn = Database_open(filename, action, max_rows, max_data);
  int id = 0;

  if (argc > 5) id = atoi(argv[5]);
  if (id >= max_rows) die("There's not that many records.", conn);

  switch (action) {
  case 'c':
    /* Database_create(conn); */
    Database_write(conn);
    break;
  case 'g':
    if (argc != 6) {
      die("Need an id to get", conn);
    }

    Database_get(conn, id);
    break;
  case 's':
    if (argc != 8) {
      die("Need id, name, and email to set", conn);
    }

    Database_set(conn, id, argv[6], argv[7]);
    Database_write(conn);
    break;
  case 'd':
    if (argc != 6) {
      die("Need id to delete", conn);
    }

    Database_delete(conn, id);
    Database_write(conn);
    break;
  case 'l':
    Database_list(conn);
    break;
  default:
    die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
  }

  Database_close(conn);

  return 0;
}
