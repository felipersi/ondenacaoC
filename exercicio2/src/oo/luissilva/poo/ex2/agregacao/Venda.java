package oo.luissilva.poo.ex2.agregacao;

public class Venda {
    private Vendedor v;
    private Produto p;

    public void concretizaVenda(double preco) {
        p = new Produto();
        v = new Vendedor();

        p.setPreco(preco);
        double comissao = p.getPreco() * 0.1;
        v.setComissao(comissao);
        p.vendido();
        System.out.println("Venda Realizada! - Comissao: R$ " + comissao);
    }
}
