import 'package:flutter/material.dart';
import 'data.dart';
import 'widgets.dart';
import 'constants.dart';

class InicioPage extends StatefulWidget {
  const InicioPage({super.key});

  @override
  State<InicioPage> createState() => _InicioPageState();
}

class _InicioPageState extends State<InicioPage> {
  @override
  Widget build(BuildContext context) {
    final visitados =
        clientesRuta.where((c) => c['estado'] == 'Visitado').length;
    final totalPedido = cartTotal();

    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        SectionCard(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(vendedor['nombre']!, style: titleStyle),
              const SizedBox(height: 4),
              Text('${vendedor['codigo']} - ${vendedor['zona']}',
                  style: bodyStyle),
              const SizedBox(height: 16),
              PrimaryButton(
                text: checkedIn ? 'Jornada iniciada' : 'Iniciar jornada',
                icon: checkedIn ? Icons.check_circle : Icons.play_arrow,
                onPressed: () {
                  setState(() => checkedIn = true);
                  showMessage(context, 'Check-in registrado en Lima Este');
                },
              ),
            ],
          ),
        ),
        const SizedBox(height: 12),
        Row(
          children: [
            Expanded(
                child: MetricCard(
                    label: 'Visitas',
                    value: '$visitados/${clientesRuta.length}')),
            const SizedBox(width: 12),
            Expanded(child: MetricCard(label: 'Pedido', value: money(totalPedido))),
          ],
        ),
        const SizedBox(height: 12),
        const SectionCard(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text('Alertas comerciales', style: titleStyle),
              SizedBox(height: 12),
              AlertRow(text: '1 cliente con deuda vencida', danger: true),
              AlertRow(text: 'Promocion 12+1 activa en abarrotes', danger: false),
              AlertRow(text: 'Modo offline disponible', danger: false),
            ],
          ),
        ),
      ],
    );
  }
}

class RutaPage extends StatefulWidget {
  const RutaPage({super.key});

  @override
  State<RutaPage> createState() => _RutaPageState();
}

class _RutaPageState extends State<RutaPage> {
  @override
  Widget build(BuildContext context) {
    return ListView.separated(
      padding: const EdgeInsets.all(16),
      itemCount: clientesRuta.length,
      separatorBuilder: (_, __) => const SizedBox(height: 12),
      itemBuilder: (context, index) {
        final cliente = clientesRuta[index];
        final visitado = cliente['estado'] == 'Visitado';
        final deuda = cliente['deuda'] != 'S/ 0.00';

        return SectionCard(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Row(
                children: [
                  CircleAvatar(
                    backgroundColor: visitado ? seaGreen : blueSlate,
                    foregroundColor: Colors.white,
                    child: Text('${index + 1}'),
                  ),
                  const SizedBox(width: 12),
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(cliente['nombre'].toString(), style: titleStyle),
                        Text(cliente['direccion'].toString(), style: bodyStyle),
                      ],
                    ),
                  ),
                ],
              ),
              const SizedBox(height: 12),
              Row(
                children: [
                  StatusChip(
                      text: cliente['estado'].toString(),
                      color: visitado ? seaGreen : blueSlate),
                  const SizedBox(width: 8),
                  StatusChip(
                      text: 'Deuda ${cliente['deuda']}',
                      color: deuda ? nightBordeaux : seaGreen),
                ],
              ),
              const SizedBox(height: 12),
              PrimaryButton(
                text: visitado ? 'Visita completada' : 'Marcar visita',
                icon: visitado ? Icons.check : Icons.location_on,
                onPressed: visitado
                    ? null
                    : () {
                        setState(() => cliente['estado'] = 'Visitado');
                        showMessage(
                            context, 'Visita registrada: ${cliente['nombre']}');
                      },
              ),
            ],
          ),
        );
      },
    );
  }
}

class PedidosPage extends StatefulWidget {
  const PedidosPage({super.key});

  @override
  State<PedidosPage> createState() => _PedidosPageState();
}

class _PedidosPageState extends State<PedidosPage> {
  @override
  Widget build(BuildContext context) {
    final total = cartTotal();

    return Column(
      children: [
        Expanded(
          child: ListView.separated(
            padding: const EdgeInsets.all(16),
            itemCount: productos.length,
            separatorBuilder: (_, __) => const SizedBox(height: 12),
            itemBuilder: (context, index) {
              final producto = productos[index];
              final qty = producto['qty'] as int;

              return SectionCard(
                child: Row(
                  children: [
                    Expanded(
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(producto['nombre'].toString(),
                              style: titleStyle),
                          const SizedBox(height: 4),
                          Text(
                              '${producto['sku']} - Stock ${producto['stock']}',
                              style: bodyStyle),
                          const SizedBox(height: 8),
                          Text(money(producto['precio'] as double),
                              style: priceStyle),
                        ],
                      ),
                    ),
                    QuantityControl(
                      value: qty,
                      onMinus: () => setState(() {
                        if (qty > 0) producto['qty'] = qty - 1;
                      }),
                      onPlus: () => setState(() {
                        if (qty < (producto['stock'] as int)) {
                          producto['qty'] = qty + 1;
                        }
                      }),
                    ),
                  ],
                ),
              );
            },
          ),
        ),
        Container(
          padding: const EdgeInsets.fromLTRB(16, 12, 16, 16),
          decoration: const BoxDecoration(
            color: Colors.white,
            border: Border(top: BorderSide(color: silver)),
          ),
          child: Row(
            children: [
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  mainAxisSize: MainAxisSize.min,
                  children: [
                    const Text('Total pedido',
                        style: TextStyle(
                            color: blueSlate, fontWeight: FontWeight.w600)),
                    Text(money(total),
                        style: const TextStyle(
                            fontSize: 22, fontWeight: FontWeight.w700)),
                  ],
                ),
              ),
              ElevatedButton.icon(
                style: ElevatedButton.styleFrom(
                  backgroundColor: seaGreen,
                  foregroundColor: Colors.white,
                  minimumSize: const Size(148, 48),
                  shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(8)),
                ),
                onPressed: total <= 0
                    ? null
                    : () {
                        for (final producto in productos) {
                          producto['qty'] = 0;
                        }
                        setState(() {});
                        showMessage(context, 'Pedido registrado correctamente');
                      },
                icon: const Icon(Icons.send),
                label: const Text('Registrar'),
              ),
            ],
          ),
        ),
      ],
    );
  }
}
