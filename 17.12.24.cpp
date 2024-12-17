#include <iostream>
using namespace std;
struct pryam
{
    int len;
    int wei;
};
pryam summ(pryam a, pryam b) {
    pryam res;
    res.len = a.len + b.len;
    res.wei = a.wei + b.wei;
    return res;
}
pryam minus(pryam a, pryam b) {
    pryam res;
    res.len = a.len - b.len;
    res.wei = a.wei - b.wei;
    return res;
}
pryam proi(pryam a, pryam b) {
    pryam res;
    res.len = a.len * b.len;
    res.wei = a.wei * b.wei;
    return res;
}
double del(pryam a, pryam b) {
    double perv=a.len / b.len;
    double vtor = a.wei / b.wei; 
    double res = perv*vtor;

    return res;
}
int main()
{
    pryam a;
    a.len = 4;
    a.wei = 4;
    pryam b;
    b.len = 2;
    b.wei = 2;
}

