#include <iostream>

#pragma pack(push, 1)

// alignas is more important
struct alignas(16) mystruct
{
    uint16_t data1;
    uint64_t data2;
};
// pragma dominates
struct mystruct1
{
    uint8_t data0;
    uint16_t data1;
    uint64_t data2;
};

#pragma pack(pop)

struct mystruct2
{
    uint8_t data0;
    uint16_t data1;
    uint64_t data2;
};


struct mystruct3 {
    uint8_t data0;
    uint16_t data1;
    uint64_t data2;
} __attribute__ ((packed));

struct alignas(16) mystruct4 {
    uint8_t data0;
} __attribute__ ((packed));


//borrowed from csapp show_bytes.c
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf("%p\t0x%.2x\n", &start[i], start[i]); 
    printf("\n");
}

int main()
{
    mystruct s[2]{0XFFFF,0XAAAA'AAAA'AAAA'AAAA};
    mystruct1 s1[2]{0X33,0XFFFF,0XAAAA'AAAA'AAAA'AAAA};
    mystruct2 s2[2]{0X33,0XFFFF,0XAAAA'AAAA'AAAA'AAAA};
    mystruct3 s3[2]{0X33,0XFFFF,0XAAAA'AAAA'AAAA'AAAA};
    
    std::cout << "0 alignas+pragma 2 size: " << sizeof(mystruct) << '\n';
    show_bytes((byte_pointer)&s, sizeof(mystruct));
    std::cout << "s[1] addr: " << &(s[1]) << std::endl;
     
    std::cout << "1 alignas size: " << sizeof(mystruct1) << '\n'; 
    std::cout << "s1[1] addr: " << &(s1[1]) << std::endl;
    show_bytes((byte_pointer)&s1, sizeof(mystruct1));
    
    
    std::cout << "2 none size: " << sizeof(mystruct2) << '\n'; 
    std::cout << "s2[1] addr: " << &(s2[1]) << std::endl;
    show_bytes((byte_pointer)&s2, sizeof(mystruct2));
    
     
    std::cout << "3 __attribute__ ((packed)) size: " << sizeof(mystruct3) << '\n'; 
    std::cout << "s3[1] addr: " << &(s3[1]) << std::endl;
    show_bytes((byte_pointer)&s3, sizeof(mystruct3));
    mystruct4 s4[2]{0};
    std::cout << "4 size: " << sizeof(mystruct4) << '\n'; 
    show_bytes((byte_pointer)&s4, sizeof(mystruct4));
    std::cout << "s4[1] addr: " << &(s4) << std::endl;
    
}