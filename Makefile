

DIRS 	 := O1 O2 O7 O9 N8
.PHONY: all clean runO1_a runO1_b runO2_a runO2_b runO7

all:
	for DIR in ${DIRS}; do \
		cd $${DIR} && ${MAKE}; \
		cd ..; \
	done

clean:
	for DIR in ${DIRS}; do \
		cd $${DIR} && ${MAKE} clean; \
		cd ..; \
	done