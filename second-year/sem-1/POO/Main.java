package ProblemaFisiere;

class Fisier{
    private String nume,continut;
    private int id;
    private static int contor=0;
    private Fisier versant;
    private int nrconcat=0;

    public Fisier(String nume,String continut)
    {
        this.nume=nume;
        this.continut=continut;
        contor++;
        this.id=contor;
        this.versant=null;
    }

    public void salveazaVersiune()
    {
        Fisier nou= new Fisier(this.nume+"bak",this.continut);
        nou.versant=this.versant;
        this.versant=nou;

    }
    public void concateneaza(Fisier f1)
    {
        this.salveazaVersiune();
        this.continut=this.continut+f1.continut;
        this.nrconcat++;
    }
    public String toString()
    {
        if(this.versant==null)
        {
            return (this.id+" "+this.nume+" [ "+this.continut+" ]");
        }
        else
        {
            return (this.id+" "+this.nume+" [ "+this.continut+" ]"+"<"+this.versant.toString()+">");
        }
    }
    public int numarConcatenari()
    {
        return this.nrconcat;
    }

}

public class Main {
    public static void main(String[] args) {
        Fisier f1=new Fisier("fis1","ana are mere");
        System.out.println(f1);
        f1.concateneaza(new Fisier("fis2"," si pere"));
        System.out.println(f1);
        System.out.println(f1.numarConcatenari());
    }
}
