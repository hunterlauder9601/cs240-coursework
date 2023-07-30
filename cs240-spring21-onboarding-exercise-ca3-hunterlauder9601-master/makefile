partA: partA.cpp
	g++ partA.cpp -o partA

runPartA: partA
	./partA $(inputdir) $(workdir)

partB: partB.cpp DLL.h DLL.cpp
	g++ -c partB.cpp -o partB.o
	g++ -c DLL.cpp -o DLL.o
	g++ partB.o DLL.o -o partB

runPartB: partB
	./partB $(inputdir) $(workdir)

clean:
	rm partA partB *.o

finishedLab: clean
	git add --all
	git commit -m "lab exercise 3/25 done"
	git push
