public class CarrilEstandar extends Carril {
    @Override
    public String getTipo() {
        return "Estandar";
    }

    @Override
    public double velocidadMaxima(int km) {
        if (km<100) return 80;
        else if (km<200) return 120;
        else return 100;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad<=this.velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.equals("Motocicleta") || categoria.equals("Coupe") || categoria.equals("SUV") ||
                categoria.equals("Camioneta") || categoria.equals("Sedan") || categoria.equals("Ambulancia");
    }
}
