#include "num_complex.h"
#include <string>

void ::num_complex::set(int parte_real,int parte_imag)
    {
        this->parte_real = parte_real;
        this->parte_imag = parte_imag;
    }

    std::string num_complex::get(){
        std::string resp;
        if(this->parte_imag >=0){
            resp = std::to_string(this->parte_real)+ " + " +std::to_string(this->parte_imag)+ "i";
        }else{
            resp = std::to_string(this->parte_real)+ " - " +std::to_string(this->parte_imag)+ "i";
        }
        return resp;
    }

    num_complex num_complex::operator +(const num_complex &num) const{

        int parte_real_result = this->parte_real + num.parte_real;
        int parte_imag_result = this->parte_imag + num.parte_imag;

        return num_complex(parte_real_result, parte_imag_result);
    }

    num_complex num_complex::operator -(const num_complex &num) const{

        int parte_real_result = this->parte_real - num.parte_real;
        int parte_imag_result = this->parte_imag - num.parte_imag;

        return num_complex(parte_real_result, parte_imag_result);
    }

    num_complex num_complex::operator *(const num_complex &num) const {
        int parte_real_result = (this->parte_real * num.parte_real) - (this->parte_imag * num.parte_imag);
        int parte_imag_result = (this->parte_real * num.parte_imag) + (this->parte_imag * num.parte_real);

        return num_complex(parte_real_result, parte_imag_result);
    }

    num_complex num_complex::operator /(const num_complex &num) const {
        int denominador = num.parte_real * num.parte_real + num.parte_imag * num.parte_imag;

        int parte_real_result = (this->parte_real * num.parte_real + this->parte_imag * num.parte_imag) / denominador;
        int parte_imag_result = (this->parte_imag * num.parte_real - this->parte_real * num.parte_imag) / denominador;

        return num_complex(parte_real_result, parte_imag_result);
    }

    bool num_complex::operator ==(const num_complex &num) const {
         return this->parte_real == num.parte_real && this->parte_imag == num.parte_imag;
    }


    bool num_complex::operator !=(const num_complex &num) const {
        return this->parte_real != num.parte_real || this->parte_imag != num.parte_imag;
    }
