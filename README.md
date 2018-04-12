# TODO LIST
 - possibly separate lib out into a separate cmakelist for building into a static library for linking against
 

 # Gareth Reading Stuff
 https://tech.blog.aknin.name/tag/block-stack/
https://docs.python.org/3.5/library/dis.html#python-bytecode-instructions

https://docs.python.org/3/reference/executionmodel.html#naming-and-binding

https://docs.python.org/3/reference/executionmodel.html#naming-and-binding


Other Project Idea:
https://github.com/kayhayen/Nuitka#optimization

https://www.cs.ucsb.edu/research/tech-reports/2012-03

Jitting Guidelines 

https://www.ojdip.net/2014/06/simple-jit-compiler-cpp/

https://github.com/asmjit/asmjit <- VERY HELPFUL LIBRARY FOR WRITING JIT CODE
Should take a looks at build instructions

https://late.am/post/2012/03/26/exploring-python-code-objects.html <- great guide exploring Python Code objects, currently working on disassembling these

https://docs.python.org/2/library/code.html#module-code

Proposed Execution Workflow 
* Parse the PYC file in Python and convert it to some simple representation of the bytecode
* Move that to our own intermediate representation that we will then load and evaluate in C++

Reading lists / implementation steps
- https://tech.blog.aknin.name/2010/04/02/pythons-innards-introduction/
- https://tech.blog.aknin.name/2010/05/26/pythons-innards-pystate/
- https://tech.blog.aknin.name/2010/07/22/pythons-innards-interpreter-stacks/

When you’re “running” Python code, you’re actually evaluating frames (recall ceval.c: PyEval_EvalFrameEx). For now we’re happy to lump frame objects and code objects together; in reality they are rather distinct, but we’ll explore that some other time.