#include <iostream>
#include <cstdint>

struct Data {
    int value;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data data{ 42 };
    uintptr_t serialized = serialize(&data);
    Data* deserialized = deserialize(serialized);

    if (deserialized == &data) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "KO" << std::endl;
    }

    return 0;
}