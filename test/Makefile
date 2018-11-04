test: test_1 test_2
	@echo '--- test/Makefile $@'

test_1:
	./$(package) 1.test.c
	@echo '--- test/Makefile $@'

test_2:
	./$(package) 2.test.c
	@echo '--- test/Makefile $@'

test_0_input:
	./$(package)
	@echo '--- test/Makefile $@'

test_2_input:
	./$(package) 1.test.c 2.test.c
	@echo '--- test/Makefile $@'


.PHONY: test test_1
