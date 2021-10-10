public class HomeTheaterFacade {
    
    Dvd dvd;
    Tv tv;

    public HomeTheaterFacade(Dvd dvd, Tv tv) {
        this.tv = tv;
        this.dvd = dvd;
    }

}  

    public class Main {

    public static void main(String[] args) {
        
        Tv tv = new Tv();
        Dvd dvd  = new Dvd();
        
        HomeTheaterFacade htf = new HomeTheaterFacade(dvd, tv);
        
        htf.iniciarFilme("interestelar");
        
        htf.fimDoFilme();
    }


    public void iniciarFilme(String nomeDoFilme){
        
        System.out.println("---------------------------------------------");
        tv.ligar();
        dvd.ligado();
        dvd.play(nomeDoFilme);
        System.out.println("");
        System.out.println("---------------------------------------------");        
    }
    
    public void fimDoFilme(){
        System.out.println("---------------------------------------------");
        tv.desligar();
        dvd.stop();
        dvd.eject();
        dvd.desligado();
        System.out.println("");
        System.out.println("---------------------------------------------");  
    }
    
    
}

public class Tv {

    public void ligar() {
        System.out.println("ligar tela");
    }

    public void desligar() {
        System.out.println("desligar tela");
    }
    
}

public class Dvd {

    public void stop() {
        System.out.println("dvd parado");
    }

    public void eject() {
        System.out.println("Ejetando dvd");
    }

    public void desligado() {
        System.out.println("desligando dvd");
    }

    public void play(String nomeDoFilme) {
        System.out.println("iniciando o filme: "+ nomeDoFilme);
    }

    public void ligado() {
        System.out.println("Ligando o dvd");
    }
    
}
