public class CarrilEmergencia extends Carril {
    @Override
    public double velocidadMaxima(int km) {
        return 80;
    }

    @Override
    public String getTipo() {
        return "Emergencia";
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad<=this.velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.equals("Ambulancia") || categoria.equals("Grua");
    }
}
