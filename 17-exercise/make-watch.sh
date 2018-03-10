while inotifywait -e close_write ex17.c; do make clean; make; done
