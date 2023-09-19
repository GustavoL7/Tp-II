#ifndef NUM_COMPLEX_H
#define NUM_COMPLEX_H
#include <string>

class num_complex
    {
    private:
        int parte_real;
        int parte_imag;

    public:
        num_complex(int parte_real, int parte_imag) : parte_real(parte_real), parte_imag(parte_imag) {}
        num_complex():parte_real(0),parte_imag(0){}
        void set(int parte_real, int parte_imag);
        std::string get();
        num_complex operator +(const num_complex &num)const;
        num_complex operator -(const num_complex &num)const;
        num_complex operator *(const num_complex &num)const;
        num_complex operator /(const num_complex &num)const;
        bool operator ==(const num_complex &num) const;
        bool operator !=(const num_complex &num) const;
    };



#endif // NUM_COMPLEX_H
