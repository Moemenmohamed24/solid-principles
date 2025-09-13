// Interface Pollution ده كده اكبر غلط لان انا عملت
class IMachine {
public:
    virtual void Print() = 0;
    virtual void Scan() = 0;
    virtual void Fax() = 0;
};

// ده كلاس عادي عامل توريث
class Printer : public IMachine {
public:
    void Print() override {
        // دي داله  انا عايزها في الكلاس
    }
    void Scan() override {
        // interface مش محتاج، بس مضطر أعمله علشان الكلاس الاساسي 
    }
    void Fax() override {
        // interface مش محتاج، بس مضطر أعمله علشان الكلاس الاساسي 
    }
};


//<------------------------------------------ISP الحل مع ------------------------->
// واجهة الطباعة
class IPrinter {
public:
    virtual void Print() = 0;
};

// واجهة الماسح الضوئي
class IScanner {
public:
    virtual void Scan() = 0;
};

// واجهة الفاكس
class IFax {
public:
    virtual void Fax() = 0;  
};

// كلاس الطابعة العادية يستخدم واجهة الطباعة بس
class SimplePrinter : public IPrinter {
public:
    void Print() override {
        // 
    }
};

// كلاس الماسح الضوئي يستخدم واجهة الماسح الضوئي بس
class SimpleScanner : public IScanner {
public:
    void Scan() override {
        // منطق المسح
    }
};

// كلاس الفاكس يستخدم واجهة الفاكس بس
class SimpleFax : public IFax {
public:
    void Fax() override {
        // منطق الفاكس
    }
};

// كلاس جهاز متعدد الوظائف يورث من كل الواجهات اللي محتاجها
class MultiFunctionMachine : public IPrinter, public IScanner, public IFax {
public:
    void Print() override { /* print logic */ }
    void Scan() override { /* scan logic */ }
    void Fax() override { /* fax logic */ }
};
