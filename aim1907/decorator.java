public abstract class Componente {
    String metodoA;
    double metodoB;
 
    public String metodoA() {
        return nome;
    }
 
    public double metodoB() {
        return preco;
    }
}

public class CompnenteConcreto extends Componente {
    public ComponenteConcreto() {
        nome = "Cachaça";
        preco = 1.5;
    }
}

public abstract class ComponenteDecorator extends Componente {
    Componente coquetel;
 
    public ComponenteDecorator(Coquetel umCoquetel) {
        coquetel = umCoquetel;
    }
 
    @Override
    public String getNome() {
        return coquetel.getNome()  + " + " + nome;
    }
 
    public double getPreco() {
        return coquetel.getPreco() + preco;
    }
}


public class Suco extends ComponenteDecorator {
 
    public Suco(Componente umCoquetel) {
        super(umCoquetel);
        nome = "Suco";
        preco = 5.0;
    }
 
}

public class Limão extends ComponenteDecorator {
 
    public Limao(Componente umCoquetel) {
        super(umCoquetel);
        nome = "Limão";
        preco = 0.5;
    }
 
}


public static void main(String[] args) {
        Componente meuCoquetel = new Cachaca();
        System.out.println(meuCoquetel.getNome() + " = "
                + meuCoquetel.getPreco());
 
        meuCoquetel = new Refrigerante(meuCoquetel);
        System.out.println(meuCoquetel.getNome() + " = "
                + meuCoquetel.getPreco());
    }