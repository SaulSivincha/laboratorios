int selectedTab = 0;
bool checkedIn = false;

final vendedor = {
  'nombre': 'Carlos Rojas',
  'codigo': 'VEN-024',
  'zona': 'Lima Este',
};

final clientesRuta = [
  {
    'nombre': 'Bodega San Jose',
    'direccion': 'Av. Proceres 1240, SJL',
    'estado': 'Pendiente',
    'deuda': 'S/ 0.00',
  },
  {
    'nombre': 'Minimarket Las Flores',
    'direccion': 'Jr. Los Geranios 455, Ate',
    'estado': 'Pendiente',
    'deuda': 'S/ 128.50',
  },
  {
    'nombre': 'Comercial El Sol',
    'direccion': 'Av. Separadora Industrial 818',
    'estado': 'Pendiente',
    'deuda': 'S/ 0.00',
  },
];

final productos = [
  {
    'nombre': 'Aceite Primor 1L',
    'sku': 'ACE-1001',
    'precio': 8.90,
    'stock': 42,
    'qty': 0,
  },
  {
    'nombre': 'Arroz Costeno 5kg',
    'sku': 'ARR-5005',
    'precio': 24.50,
    'stock': 18,
    'qty': 0,
  },
  {
    'nombre': 'Detergente Bolivar 800g',
    'sku': 'LIM-0800',
    'precio': 10.20,
    'stock': 31,
    'qty': 0,
  },
];

double cartTotal() {
  var total = 0.0;
  for (final producto in productos) {
    total += (producto['precio'] as double) * (producto['qty'] as int);
  }
  return total;
}
