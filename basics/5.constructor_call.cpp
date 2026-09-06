// Can We Call Constructor Ourselves?

// Suppose

// Student s1;

// Can we do

// s1.Student();

// No.
// Constructors are not ordinary member functions. They are invoked automatically during object creation.
// If you need to reinitialize an object later, create a separate member function like reset() instead.