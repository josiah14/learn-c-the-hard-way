all:
	$(MAKE) -C 1-exercise
	$(MAKE) -C 3-exercise
	$(MAKE) -C 7-exercise

clean:
	$(MAKE) clean -C 1-exercise
	$(MAKE) clean -C 3-exercise
	$(MAKE) clean -C 7-exercise
