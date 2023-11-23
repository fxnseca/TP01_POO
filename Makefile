all: compile run
test: compiletest runtest

compile:
	g++ main.cpp dados.cpp imovel.cpp apartamento.cpp casa.cpp chacara.cpp -o main

run:
	./main

compiletest:
	g++ test.cpp -o test

runtest:
	./test