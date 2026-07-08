import java.util.Scanner;

public class Bebida extends Producto {
    private char tipoBebida;

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        this.tipoBebida=archivo.next().charAt(0);
    }

    @Override
    public void imprimir() {
        super.imprimir();
    }

    @Override
    public void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais);
        if (this.tipoBebida=='C') System.out.println("Tipo: Cafe");
        else if (this.tipoBebida=='H') System.out.println("Tipo: Chocolate");
        else if (this.tipoBebida=='T') System.out.println("Tipo: Te");
        else System.out.println("Tipo: Infusion");
    }

    public char getTipoBebida() {
        return tipoBebida;
    }

    public void setTipoBebida(char tipoBebida) {
        this.tipoBebida = tipoBebida;
    }
}
