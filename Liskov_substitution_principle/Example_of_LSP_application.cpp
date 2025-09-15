class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying" << std::endl;
    }
   
};
//النعامه تورثت من الطيور اللي هو اصلا فيه طياران بس لو جيبت بدلت النعامه مع الطيور والحاجه اللي بتحصل فيه هتلاققي نتيجه مش مظبوطه اصلا لان النعامه مش بتطير
class Ostrich : public Bird {
public:
    void fly() override {
        throw runtime_error("Ostrich cannot fly!"); // 
    }
};

int main() {
    Bird b1;
    b1.fly(); 

    Ostrich o;  
        o.fly();//هنا هيظهر ان  النعامه بتطير وده غلط
    
    return 0;
}

//<------------------------------Solution with LSP-------------------------->

//حطينا الحاجه المشتركه بين كل الطيور 
class Bird
{
public:
    virtual void eat() = 0; 
    virtual ~Bird() = default;
};

// الطيور اللي بتطير بس
class FlyingBird
{
public:
    virtual void fly() = 0;  
    virtual ~FlyingBird() = default;
};

class Sparrow : public Bird , public FlyingBird
{
public:
    void eat() override
    {
        cout << "Sparrow is eating" << endl;
    }
    void fly() override
    {
        cout << "Sparrow is flying" << endl;
    }
};

//النعامه تاخد الاكل بس 
class Ostrich : public Bird
{
public:
    void eat() override
    {
        cout << "Ostrich is eating" << endl;
    }
};

int main()
{
    Sparrow s;
    s.eat();
    s.fly();

    Ostrich o;
    o.eat();   

    return 0;










