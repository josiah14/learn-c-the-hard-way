all:
	$(MAKE) -C 1-exercise
	$(MAKE) -C 3-exercise
	$(MAKE) -C 7-exercise
	$(MAKE) -C 8-exercise
	$(MAKE) -C 9-exercise

clean:
	$(MAKE) clean -C 1-exercise
	$(MAKE) clean -C 3-exercise
	$(MAKE) clean -C 7-exercise
	$(MAKE) clean -C 8-exercise
	$(MAKE) clean -C 9-exercise
