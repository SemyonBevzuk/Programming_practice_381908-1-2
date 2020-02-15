//
// Created by Kirill Lakhov on 14.02.2020.
//

#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>

Matrix::Matrix(int size) {
    this->contents = new int*[size];
    this->size = size;
    for (int i = 0; i < size; ++i) {
        this->contents[i]=new int[size];
    }
    this->initZero();
}

void Matrix::initZero() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->contents[i][j] = 0;
        }
    }
}

void Matrix::randomInit() {
    std::mt19937 generator(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    std::uniform_int_distribution<> uid(0,100);
    for (int j = 0; j <this->size; ++j) {
        for (int i = 0; i < this->size; ++i) {
            this->contents[j][i] = uid(generator);
        }
    }
}
bool Matrix::add(Matrix _m) {
    if(this->size == _m.size){
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->contents[i][j]+=_m.contents[i][j];
            }
        }
        return true;
    }
    return false;
}

bool Matrix::init(int size, int**arr) {
    if(this->size == size){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                this->contents[i][j] = arr[i][j];
            }
        }
        return true;
    }
    return false;
}
int Matrix::get(int _i, int _j) {
    if(_i<this->size && _j<this->size){
        return this->contents[_i][_j];
    }else{
        throw std::range_error("Matrix indexing out of range.");
    }
}

bool Matrix::out(const std::string& filename){
    std::fstream f;
    f.open(filename,std::fstream::out);
    if(f.is_open()){
        f<<this->size<<"\n";
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                f<<this->contents[i][j]<<" ";
            }
            f<<"\n";
        }
        f.close();
        return true;
    }
    return false;
};

Matrix* Matrix::in(const std::string &filename) {
        std::fstream f;
        f.open(filename,std::fstream::in);
        if(f.is_open()){
            int size=0;
            f>>size;
            int**arr = new int*[size];
            for (int k = 0; k < size; ++k) {
                arr[k] = new int[size];
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    f>>arr[i][j];
                }
            }
            f.close();
            auto *m = new Matrix(size);
            m->init(size,arr);
            return m;
        }
}
void Matrix::print(){
    for (int i = 0; i < this->size; ++i) {
        std::cout<<"line #"<<i<<std::endl;
        for (int j = 0; j < this->size; ++j) {
            std::cout<<this->contents[i][j]<<" ";
        }
        std::cout<<"\n"<<"";
    }
}
int Matrix::matrixCount = 0;
