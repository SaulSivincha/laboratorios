import 'package:flutter/material.dart';
import 'constants.dart';

class SectionCard extends StatelessWidget {
  const SectionCard({required this.child, super.key});

  final Widget child;

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: Colors.white,
        border: Border.all(color: silver),
        borderRadius: BorderRadius.circular(8),
      ),
      child: child,
    );
  }
}

class MetricCard extends StatelessWidget {
  const MetricCard({required this.label, required this.value, super.key});

  final String label;
  final String value;

  @override
  Widget build(BuildContext context) {
    return SectionCard(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(label, style: bodyStyle),
          const SizedBox(height: 8),
          Text(value,
              style: const TextStyle(
                  color: blueSlate, fontSize: 24, fontWeight: FontWeight.w700)),
        ],
      ),
    );
  }
}

class AlertRow extends StatelessWidget {
  const AlertRow({required this.text, required this.danger, super.key});

  final String text;
  final bool danger;

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(bottom: 8),
      child: Row(
        children: [
          Icon(danger ? Icons.warning_amber : Icons.check_circle_outline,
              color: danger ? nightBordeaux : seaGreen),
          const SizedBox(width: 8),
          Expanded(child: Text(text, style: bodyStyle)),
        ],
      ),
    );
  }
}

class StatusChip extends StatelessWidget {
  const StatusChip({required this.text, required this.color, super.key});

  final String text;
  final Color color;

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 6),
      decoration: BoxDecoration(
        color: color.withValues(alpha: 0.10),
        borderRadius: BorderRadius.circular(999),
        border: Border.all(color: color.withValues(alpha: 0.35)),
      ),
      child: Text(text,
          style: TextStyle(
              color: color, fontSize: 12, fontWeight: FontWeight.w700)),
    );
  }
}

class PrimaryButton extends StatelessWidget {
  const PrimaryButton({
    required this.text,
    required this.icon,
    required this.onPressed,
    super.key,
  });

  final String text;
  final IconData icon;
  final VoidCallback? onPressed;

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: double.infinity,
      height: 48,
      child: ElevatedButton.icon(
        style: ElevatedButton.styleFrom(
          backgroundColor: seaGreen,
          foregroundColor: Colors.white,
          disabledBackgroundColor: silver,
          disabledForegroundColor: blueSlate,
          shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
        ),
        onPressed: onPressed,
        icon: Icon(icon),
        label: Text(text, style: const TextStyle(fontWeight: FontWeight.w700)),
      ),
    );
  }
}

class QuantityControl extends StatelessWidget {
  const QuantityControl({
    required this.value,
    required this.onMinus,
    required this.onPlus,
    super.key,
  });

  final int value;
  final VoidCallback onMinus;
  final VoidCallback onPlus;

  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        IconButton.filledTonal(
          style: IconButton.styleFrom(fixedSize: const Size(44, 44)),
          onPressed: onMinus,
          icon: const Icon(Icons.remove),
        ),
        SizedBox(
          width: 34,
          child: Text('$value',
              textAlign: TextAlign.center,
              style: const TextStyle(fontWeight: FontWeight.w700)),
        ),
        IconButton.filled(
          style: IconButton.styleFrom(
              backgroundColor: seaGreen,
              foregroundColor: Colors.white,
              fixedSize: const Size(44, 44)),
          onPressed: onPlus,
          icon: const Icon(Icons.add),
        ),
      ],
    );
  }
}
