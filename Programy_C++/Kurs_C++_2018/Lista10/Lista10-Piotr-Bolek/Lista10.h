#ifndef LISTA10_H_INCLUDED
#define LISTA10_H_INCLUDED

using namespace std;
namespace strumienie
{
istream& clearline (istream& stream);
class ignore
{
    int x;
    friend istream& operator >> (istream &stream, const ignore &y)
    {
        char c;
        for(int i = 0; i < y.x; i++)
        {
            cin.get(c);
            if(c == '\n')
                break;
        }
        return stream;
    }
public:
    ignore(int ile) : x(ile) {};
};

ostream& comma (ostream& stream);

ostream& colon (ostream& stream);

class index
{
    int x, w;
    friend ostream& operator << (ostream& stream,  const index &x)
    {
        stream<<"["<<setw(x.w)<<x.x<<"]";
        return stream;
    }
public:
    index(int x2, int w2) : x(x2), w(w2) {};
};

}

#endif // LISTA10_H_INCLUDED
