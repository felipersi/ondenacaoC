package oo.luissilva.poo.ex2.agregacao;

public class Vendedor {
    private double comissao;

    public double getComissao() {
        return comissao;
    }

    public void setComissao(double comissao) {
        this.comissao = comissao;
    }
    public void vende() {
        System.out.println("Vendido");
    }
}

