clear;
close all;
clc;

% Laboratorio 5 - Ejercicio 2
% Enunciado:
% Encuentre, el potencial electrico en un cuadrado de 1 cm de lado.
% (a) Todas las cargas iguales positivas.
% (b) Todas las cargas iguales negativas.
% (c) Cargas intercaladas con positivos y negativos.
%
% Implementacion:
% Se calcula el potencial total V para las cuatro cargas en los vertices.

k = 1;
L = 1;
a = L / 2;

xa = -2.1:0.05:2.1;
ya = -2.1:0.05:2.1;
[x, y] = meshgrid(xa, ya);

xc = [a, -a, -a, a];
yc = [a, a, -a, -a];

casos = [
     1,  1,  1,  1;
    -1, -1, -1, -1;
     1, -1,  1, -1
];

titulos = {
    '(a) Todas las cargas positivas'
    '(b) Todas las cargas negativas'
    '(c) Cargas intercaladas'
};

figure('Name', 'L5 Ejercicio 2 - Potencial electrico en cuadrado');

for caso = 1:size(casos, 1)
    q = casos(caso, :);
    V = potencialElectrico(x, y, xc, yc, q, k);

    subplot(1, 3, caso);
    niveles = nivelesContorno(V, 45);
    contour(x, y, V, niveles);
    colorbar;
    hold on;
    dibujarCargas(xc, yc, q);
    plot([xc, xc(1)], [yc, yc(1)], 'k:');
    axis equal;
    axis([-1.7 1.7 -1.7 1.7]);
    grid on;
    xlabel('x');
    ylabel('y');
    title(titulos{caso});
    hold off;
end

function V = potencialElectrico(x, y, xc, yc, q, k)
    V = zeros(size(x));

    for i = 1:numel(q)
        r = sqrt((x - xc(i)).^2 + (y - yc(i)).^2);
        r(r < 0.03) = NaN;
        V = V + k * q(i) ./ r;
    end
end

function niveles = nivelesContorno(V, cantidad)
    valores = V(isfinite(V));
    niveles = linspace(min(valores), max(valores), cantidad);
end

function dibujarCargas(xc, yc, q)
    positivas = q > 0;
    negativas = q < 0;

    plot(xc(positivas), yc(positivas), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 7);
    plot(xc(negativas), yc(negativas), 'bo', 'MarkerFaceColor', 'b', 'MarkerSize', 7);
end
