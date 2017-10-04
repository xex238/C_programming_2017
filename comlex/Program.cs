using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class pivo
{
    public virtual void a ()
    {
        Console.WriteLine("Метод базового класса");
    }
}
public class pivasic : pivo
{
    public override void  a()
    {
        Console.WriteLine("Метод производного класса");
    }
}
namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            pivasic q = new pivasic();
            q.a();
            pivo qq = new pivo();
            qq.a();
            pivo qqq = (pivo)q;
            qqq.a();
            pivo qqqq = new pivasic();
            qqqq.a();
        }
    }
}
