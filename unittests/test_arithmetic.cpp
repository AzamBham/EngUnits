#include<iostream>
#include<cassert>

#include <engunits/distance.h>

void almost_equal(double self, double other) {
    if (self==0 || other==0) {
        assert(self==other);
        return;
    }
    assert(self * 0.99 < other && other < self * 1.01);
}

int main() {
    using namespace std;
    using namespace engunits::distance;

    cout << "---Testing Arithmetic Operations with Doubles---" << endl;
    cout << "Addition: ";
    meters mp{10};
    feet fp{20};
    inches ip{100.55};
    mp += 10;
    assert(mp.scalar() == 20);
    fp += 20;
    assert(fp.scalar() == 40);
    assert((meters{} + 5).scalar() == 5);
    cout << "success" << endl;
    cout << endl;

    cout << "---Testing Arithmetic Operations with Other Units---" << endl;
    cout << "Addition: ";
    meters mma{10};
    feet ffa{10};
    mma += ffa;
    ffa += mma+ffa;

    meters mma2{0.2323};
    feet ffa2{5203};
    inches inna2{1022};

    cout << endl;

    cout << "---Random Tests---" << endl;


    cout << endl;
    cout << "All Tests Successfully Completed" << endl;
    cout << endl;

    return 0;
}