class calc{
  private:
    int c_value = 0;
  
  public:
    //constructor
    calc(){}
    calc(int v);

    //setters
    void setValue(int v){c_value = v;}
    //getters
    int getValue(){return c_value;}

    //calculator -  Haveing return as calc& lets chaining functions.
    calc& add(int v);
    calc& sub(int v);
    calc& div(int v);
    calc& mul(int v);
    calc& pow2();
    calc& powOf(int v);

    //Operator Overloading.
    calc operator+(const calc& c);
    calc operator-(const calc& c);
    calc operator/(const calc& c);
    calc operator*(const calc& c);

    bool operator<(const calc& c);
    bool operator<=(const calc& c);
    bool operator>(const calc& c);
    bool operator>=(const calc& c);
    bool operator==(const calc& c);
};

calc::calc(int v){
  setValue(v);
}

calc& calc::add(int v){
  c_value += v;
  return *this;
}

calc& calc::sub(int v){
  c_value -= v;
  return *this;
}

calc& calc::div(int v){
  c_value /= v;
  return *this;
}

calc& calc::mul(int v){
  c_value *= v;
  return *this;
}

calc& calc::pow2(){
  c_value *= c_value;
  return *this;
}

calc& calc::powOf(int v){
  int temp = c_value;
  if(v<=0){
    c_value = 0;
  }
  else{
    for(int i = 1; i < v ; i++){
      c_value *= temp;
    }
  }
  return *this;
}


//Operators
calc calc::operator+(const calc& c){
  calc temp_value = calc(0);
  temp_value.c_value = this->c_value + c.c_value;
  return temp_value;
}

calc calc::operator-(const calc& c){
  calc temp_value = calc(0);
  temp_value.c_value = this->c_value - c.c_value;
  return temp_value;
}

calc calc::operator/(const calc& c){
  calc temp_value = calc(0);
  temp_value.c_value = this->c_value / c.c_value;
  return temp_value;
}

calc calc::operator*(const calc& c){
  calc temp_value = calc(0);
  temp_value.c_value = this->c_value * c.c_value;
  return temp_value;
}


bool calc::operator<(const calc& c){
  return this->c_value < c.c_value;
}

bool calc::operator<=(const calc& c){
  return this->c_value <= c.c_value;
}

bool calc::operator>(const calc& c){
  return this->c_value > c.c_value;
}

bool calc::operator>=(const calc& c){
  return this->c_value >= c.c_value;
}

bool calc::operator==(const calc& c){
  return this->c_value == c.c_value;
}
