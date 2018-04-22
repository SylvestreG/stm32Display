#include <types.h>
#include <libc.h>

#define CHUNK_SIZE  16

template <class T>
class  Vector
{
  private:
    T* _buffer;
    size_t _size;
    size_t _capacity;

  public:
    typedef T* Iterator;

    Vector(void);
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T>& v);

    ~Vector(void);

    size_t capacity(void) const;
    size_t size(void) const;
    bool empty(void) const;

    Iterator begin(void);
    Iterator end(void);
    T& front(void);
    T& back(void);
    void push_back(const T& value);
    void pop_back(void);

    void reserve(size_t capacity);
    void resize(size_t size);

    T & operator[](unsigned int index);
    Vector<T> & operator = (const Vector<T> &);
    void clear();
};

template<class T>
Vector<T>::Vector()
{
  _capacity = 0;
  _size = 0;
  _buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
  _size = v._size;
  _capacity = v._capacity;
  _buffer = new T[_size];
  for (unsigned int i = 0; i < _size; i++)
    _buffer[i] = v._buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
  _size = size;
  _capacity = size;
  _buffer = new T[_capacity];
}

template <class T> bool
Vector<T>:: empty() const
{
  return _size == 0;
}

template<class T>
Vector<T>::Vector(unsigned int size, const T& initial)
{
  _size = size;
  _capacity = _size;
  _buffer = new T [_capacity];
  for (unsigned int i = 0; i < _size; i++)
    _buffer[i] = initial;
}

template<class T> Vector<T>&
Vector<T>::operator=(const Vector<T> & v)
{
  delete[] _buffer;
  _size = v._size;
  _capacity = v._capacity;
  _buffer = new T [_capacity];
  for (unsigned int i = 0; i < _size; i++)
    _buffer[i] = v.buffer[i];
  return *this;
}

template<class T> typename Vector<T>::Iterator
Vector<T>::begin()
{
  return _buffer;
}

template<class T> typename Vector<T>::Iterator
Vector<T>::end()
{
  return _buffer + _size;
}

template<class T> T&
Vector<T>::front()
{
  return _buffer[0];
}

template<class T> T&
Vector<T>::back()
{
  return _buffer[_size - 1];
}

template<class T> void
Vector<T>::push_back(const T & v)
{
  if (_size >= _capacity)
    this->reserve(_capacity + 16);
  _buffer [_size++] = v;
}

template<class T> void
Vector<T>::pop_back()
{
  _size--;
}

template<class T> void
Vector<T>::reserve(size_t capacity)
{
    T * newBuffer = new T[capacity];

    for (unsigned int i = 0; i < _size; i++)
        newBuffer[i] = _buffer[i];

    _capacity = capacity;
    delete[] _buffer;
    _buffer = newBuffer;
}

template<class T> size_t
Vector<T>::size(void) const
{
    return _size;
}

template<class T> void
Vector<T>::resize(size_t size)
{
    reserve(size);
    _size = size;
}

template<class T> T&
Vector<T>::operator[](unsigned int index)
{
    return _buffer[index];
}

template<class T> size_t
Vector<T>::capacity(void) const
{
    return _capacity;
}

template<class T>
Vector<T>::~Vector(void)
{
    delete[] _buffer;
}

template <class T> void
Vector<T>::clear(void)
{
    _capacity = 0;
    _size = 0;
    _buffer = 0;
}
