#include <algorithm>
#include <initializer_list>
#include <iostream>

template <typename T>
class Array
{
public:
    // конструкторы
    Array();
    Array(const std::initializer_list<T>&);
    Array(const size_t size);
    Array(const Array&);
    // оператор присваиваний
    Array& operator =(const Array&);
    // деструктор
    ~Array();

    // итераторы начала и конца контейнера
    T* begin() const;
    T* end() const;

    // опреаторы доступа
    T& operator [](const size_t);
    const T& operator [](const size_t) const;

    // прочие методы
    size_t size() const;
    void print();

    // операторы сравненния
    bool operator ==(const Array&);
    bool operator !=(const Array&);

protected:
    void swap(Array&, Array&);
    T* m_data;
    size_t m_size;
};

template <typename T>
Array<T>::Array() :
    m_data(nullptr),
    m_size(0)
{}

template <typename T>
Array<T>::Array(const size_t size) :
    m_data(new T[size]),
    m_size(size)
{
    // вызываем конструкторы для каждого элемента
    std::fill(m_data, m_data + m_size, T());
}

template<typename T>
Array<T>::Array(const std::initializer_list<T>& il) :
    m_data(new T[il.size()]),
    m_size(il.size())
{
    std::copy(il.begin(), il.end(), m_data);
}

template <typename T>
Array<T>::Array(const Array& arr)
{
    m_size = arr.m_size;
    if (arr.m_data)
    {
        m_data = new T[m_size];
        // копируем элементы в новый контейнер
        std::copy(arr.m_data, arr.m_data + m_size, m_data);
    }
    else
        m_data = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator =(const Array& arr)
{
    // исключаем работу при присваивании самому себе
    if (this != &arr)
        Array(arr).swap(*this); // Copy-and-swap idiom
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T>
T* Array<T>::begin() const
{
    return m_data;
}

template <typename T>
T* Array<T>::end() const
{
    return m_data + m_size;
}

template <typename T>
T& Array<T>::operator [](const size_t index)
{
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator [](const size_t index) const
{
    return m_data[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return m_size;
}

template <typename T>
void Array<T>::swap(Array& first, Array& second)
{
    std::swap(first.m_data, second.m_data);
    std::swap(first.m_size, second.m_size);
}

template <typename T>
bool Array<T>::operator ==(const Array& other)
{
    if (m_size != other.m_size) {
        return false;
    }
    else {
        for (int i = 0; i < m_size; i++) {
            if (m_data[i] != other.m_data[i]) {
                return false;
            }
        }
        return true;
    }
}

template <typename T>
bool Array<T>::operator !=(const Array& other)
{
    if (m_size != other.m_size) {
        return true;
    }
    else {
        for (int i = 0; i < m_size; i++) {
            if (m_data[i] != other.m_data[i]) {
                return true;
            }
        }
        return false;
    }
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < m_size; i++) {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    Array<int> a = { 1, 2, 3, 4, 5 };
    Array<int> b = { 1, 3, 3, 4, 5 };
    std::cout << "Кол-во элементов массива 1: " << a.size();
    std::cout << "| Массив:";
    a.print();
    std::cout << "Кол-во элементов массива 2: " << b.size();
    std::cout << "| Массив:";
    b.print();
    if (a == b) {
        std::cout << "Массивы равны\n" << std::endl;
    }
    else {
        std::cout << "Массивы не равны\n" << std::endl;;
    }
    Array<double> c = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    Array<double> d = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::cout << "Кол-во элементов массива 2: " << c.size();
    std::cout << "| Массив:";
    c.print();
    std::cout << "Кол-во элементов массива 3: " << d.size();
    std::cout << "| Массив:";
    d.print();
    if (c == d) {
        std::cout << "Массивы равны\n" << std::endl;
    }
    else {
        std::cout << "Массивы не равны\n" << std::endl;;
    }
    system("pause");
}

template<class T>
T sort(T arr) {
    int size = arr.size;
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
