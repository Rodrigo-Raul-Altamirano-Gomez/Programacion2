import java.io.FileNotFoundException;

public class Principal {
    public void main(String[] args) throws FileNotFoundException {
        Libreria libreria=new Libreria();
        libreria.leer();
        libreria.calcularRankings();
        libreria.imprimir();
    }
}
