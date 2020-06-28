#include <iostream>

template <class T> class Auto_ptr1 {
  T *m_ptr;

public:
  // Pass in a pointer to "own" via the constructor
  Auto_ptr1(T *ptr = nullptr) : m_ptr(ptr) {}

  // The destructor will make sure it gets deallocated
  ~Auto_ptr1() { delete m_ptr; }

  // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
};

template <class T> class Auto_ptr2 {
  T *m_ptr = nullptr;

public:
  Auto_ptr2(T *ptr = nullptr) : m_ptr(ptr) {}
  ~Auto_ptr2() { delete m_ptr; };

  Auto_ptr2(Auto_ptr2 &a) {
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;
  }

  Auto_ptr2 &operator=(Auto_ptr2 &a) {
    if (&a == this) {
      return *this;
    }

    delete m_ptr;
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;
    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }

  bool is_null() const { return m_ptr == nullptr; }
};

template <class T> class Auto_ptr3 {
  T *m_ptr = nullptr;

public:
  Auto_ptr3(T *ptr = nullptr) : m_ptr(ptr) {}
  ~Auto_ptr3() { delete m_ptr; };

  Auto_ptr3(const Auto_ptr3 &a) {
    m_ptr = new T;
    *m_ptr = *a.m_ptr;
  }

  Auto_ptr3 &operator=(const Auto_ptr3 &a) {
    if (&a == this)
      return *this;

    delete m_ptr;

    // Copy the resource
    m_ptr = new T;
    *m_ptr = *a.m_ptr;

    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }

  bool is_null() const { return m_ptr == nullptr; }
};

template <class T> class Auto_ptr4 {
  T *m_ptr;

public:
  Auto_ptr4(T *ptr = nullptr) : m_ptr(ptr) {}
  ~Auto_ptr4() { delete m_ptr; }

  //   Auto_ptr4(const Auto_ptr4 &a) {
  //     std::cout << "Deep copy constructor\n";
  //     m_ptr = new T;
  //     *m_ptr = *a.m_ptr;
  //   }

  Auto_ptr4(const Auto_ptr4 &a) = delete;

  Auto_ptr4(Auto_ptr4 &&a) : m_ptr(a.m_ptr) {
    std::cout << "Move constructor\n";
    a.m_ptr = nullptr;
  }

  Auto_ptr4 &operator=(const Auto_ptr4 &a) {
    std::cout << "Deep copy assignment \n";
    if (&a == this) {
      return this;
    }

    delete m_ptr;
    m_ptr = new T;
    *m_ptr = *a.m_ptr;

    return *this;
  }

  Auto_ptr4 &operator=(Auto_ptr4 &&a) {
    std::cout << "Move assignment \n";
    if (&a == this) {
      return *this;
    }

    delete m_ptr;
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;

    return *this;
  }
  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }

  bool is_null() const { return m_ptr == nullptr; }
};

class Resource {
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
  void say_hi() { std::cout << "Hi\n"; }
};

void someFunction() {
  Resource *ptr = new Resource; // Resource is a struct or class
  // do stuff with ptr here
  int x;
  std::cout << "Enter an integer: ";
  std::cin >> x;

  if (x == 0)
    return; // the function returns early, and ptr won’t be deleted!
  delete ptr;
}

void test_auto_ptr1() {
  Auto_ptr1<Resource> res(new Resource);
  int x;
  std::cout << "Enter an integer: ";
  std::cin >> x;

  if (x == 0)
    return; // the function returns early, and ptr won’t be deleted!
  //   delete res;
  //   delete val;
}

// due to shallow copy
void flaw_auto_ptr1() {
  Auto_ptr1<Resource> res1(new Resource);
  Auto_ptr1<Resource> res2 = nullptr;
}

void test_auto_ptr2() {
  Auto_ptr2<Resource> res1(new Resource);
  Auto_ptr2<Resource> res2;

  std::cout << "res1 is " << (res1.is_null() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.is_null() ? "null\n" : "not null\n");

  res2 = res1;
  std::cout << "\n";
  std::cout << "res1 is " << (res1.is_null() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.is_null() ? "null\n" : "not null\n");
}

Auto_ptr3<Resource> flaw_deep_copy() {
  Auto_ptr3<Resource> res(new Resource);
  return res;
}

Auto_ptr4<Resource> test_Auto_ptr4() {
  Auto_ptr4<Resource> res(new Resource);
  return res;
}

int main() {
  Auto_ptr4<Resource> main;
  main = test_Auto_ptr4();

  Auto_ptr4<Resource> res(std::move(main));

  return 0;
}