all:
	$(MAKE) -C 1-exercise
	$(MAKE) -C 3-exercise
	$(MAKE) -C 7-exercise
	$(MAKE) -C 8-exercise
	$(MAKE) -C 9-exercise
	$(MAKE) -C 10-exercise
	$(MAKE) -C 11-exercise
	$(MAKE) -C 12-exercise
	$(MAKE) -C 13-exercise
	$(MAKE) -C 14-exercise
	$(MAKE) -C 15-exercise
	$(MAKE) -C 16-exercise
	$(MAKE) -C 17-exercise

clean:
	$(MAKE) clean -C 1-exercise
	$(MAKE) clean -C 3-exercise
	$(MAKE) clean -C 7-exercise
	$(MAKE) clean -C 8-exercise
	$(MAKE) clean -C 9-exercise
	$(MAKE) clean -C 10-exercise
	$(MAKE) clean -C 11-exercise
	$(MAKE) clean -C 12-exercise
	$(MAKE) clean -C 13-exercise
	$(MAKE) clean -C 14-exercise
	$(MAKE) clean -C 15-exercise
	$(MAKE) clean -C 16-exercise
	$(MAKE) clean -C 17-exercise
