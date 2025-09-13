

using System;
abstract class calculation 
{
    public abstract double area();
}

//open for extention و يكون polymorphism اقدر احقق ال  abstract calss  ده اللي بتورث منه علشان اعمل ال 

class circel : calculation
{
    private double r = 0;
    public circel(double R)
    {
        r = R;
    }
    public override double area()
    {
        return 3.14 * r * r;
    }
}
// 1) بس للكلاس الجديد او اخدت من الكلاس الاساسي بس معدلتش فيه اي حاجه  extention يعني عملت  override  هنا انا  عملت 

class square : calculation
{
    private double r = 0;
    public square(double R)
    {
        r = R;
    }
    public override double area()
    {
        return r * r;
    }
}

// 2) التانيه بردو نفس الكلام معدلتش في اي حاجه من فوق

class tranglie : calculation
{
    private double _hight = 0;
    private double _baseLength = 0;

    public tranglie(double hight, double baseLength)
    {
        _hight = hight;
        _baseLength = baseLength;
    }

    public override double area()
    {
        return 0.5 * _baseLength * _hight;
    }
}
// 3) ودي بردو معدلتش في اي حاجه من فوق 

class Program
{
    static void Main()
    {

        calculation square = new square(5.1);
        calculation circel = new circel(5.5);
        calculation tranglie = new tranglie(2.2, 2.2);


        Console.WriteLine(tranglie.area());

    }
}
