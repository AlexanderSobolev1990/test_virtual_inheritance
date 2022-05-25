# Тест виртуального ромбовидного наследования  #

# Test virtual (diamond of death) inheritance #

Тест виртуального (ромбовидного) наследования. Все классы иерархии содеражат матрицу armadillo и один int в качестве полей.
Был удивлен, что необходмо вызывать конструктор копирования класса B в конструкторе копирования класса G, поскольку был уверен, что это надо делать только для класса F, но не последующих ступеней иерархии.

Test virtual inheritance (diamond of death) with classes all contain one armadillo  matrix and integer fields.
I was surprised that I have to call copy constructor of B in copy constructor of G class, because I thought that it is only needed if F class, being the 'top' of diamond.  
