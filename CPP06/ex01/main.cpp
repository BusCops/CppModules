#include "Serializer.hpp"

int main()
{
    Data *test = new Data;
    test->i = 42;
    test->data = "test";

    uintptr_t test2 = Serializer::serialize(test);

    std::cout << "serialized value : " << test2 << std::endl;

    Data *test3 = Serializer::deserialize(test2);

    std::cout << "deserialized value :\nint -> " << test3->i << "\nstring -> " << test3->data << std::endl;

    delete test;
}