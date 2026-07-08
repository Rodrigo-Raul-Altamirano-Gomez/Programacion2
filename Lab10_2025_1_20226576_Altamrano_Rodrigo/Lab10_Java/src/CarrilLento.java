public class CarrilLento extends Carril {
    @Override
    public String getTipo() {
        return "Lento";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 60;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad<=this.velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.equals("Camion") || categoria.equals("Tractor") || categoria.equals("Trailer");
    }
}
