//not well protected..
template <typename T>
class List
{
private:
    T *elem; // elem points to an array of sz elements of type T
    size_t max_size;
    size_t count;

public:
    // constructor: establish invariant, acquire resources
    explicit List(size_t s) : max_size{s}, count{0}
    {
        elem = new T[s];
    };
    // destructor: release resources
    ~List()
    {
        delete[] elem;
    }
    void insert(size_t i, T e)
    {
        if (i > count)
            throw "out of range";
        if (count == max_size)
            throw "full";

        if (count > 0)
        {
            for (auto j = count - 1; j >= i; j--)
            {
                elem[j + 1] = elem[j];
                cout << j << endl;
            }
        }

        elem[i] = e;
        count += 1;
    }
    void del(size_t i)
    {
        if (i >= count)
            throw "out of range";
        if (count == 0)
            throw "nothing to delete";

        for (auto j = i; j < count - 1; j++)
        {
            elem[j] = elem[j + 1];
        }
        elem[i] = T{};
    }

    const T &operator[](size_t i) const
    {
        if (i >= max_size)
            throw "out of bound";
        return elem[i];
    };
    size_t size() const { return count; }
};

#if defined MAIN && defined LIST1
int main()
{
    cout << "hello" << endl;
    {
        // cout << "try allocate a " << std::numeric_limits<int>::max() << " sized List" << endl;
        // List<double> l{std::numeric_limits<long>::max()};
        constexpr auto size{100};
        cout << "try allocate a " << size << " sized List" << endl;
        List<double> l{size};
        cout << "l size: " << l.size() << endl;
    }
    cout << "bye" << endl;
}
#endif

TEST_CASE("A simple test suite for List")
{
    SECTION("test case 1 with string")
    {
        List<int> l = List<int>(3);
        l.insert(0, 2);
        REQUIRE(l.size() == 1);
        REQUIRE(l[0] == 2);
    }
    SECTION("exceptions")
    {
        List<int> l = List<int>(3);
        l.insert(0, 1);
        CHECK_THROWS_WITH(l[5], Contains("of bound"));
    }
    SECTION("insert")
    {
        List<int> l = List<int>(8);
        l.insert(0, 3);
        l.insert(0, 2);
        l.insert(0, 1);
        CHECK_THROWS_WITH(l[10], Contains("of bound"));
        l.insert(2, 99);
        REQUIRE(l[2] == 99);
        REQUIRE(l[3] == 3);
        l.del(3);
        REQUIRE(l[3] == 0);
        l.del(0);
        REQUIRE(l[1] == 99);
    }
}