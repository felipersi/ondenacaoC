package oo.luissilva.poo.ex2.agregacao;

public class Produto {
    private double preco;
    private int tamanho;

    public double getPreco(){
        return preco;
    }

    public void setPreco (double preco) {
        this.preco = preco;
    }

    public int getTamanho(){
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public void vendido(){
        System.out.println("Vendido!");
    }
}
