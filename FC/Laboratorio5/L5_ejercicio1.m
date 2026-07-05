clear;
close all;
clc;

% Laboratorio 5 - Ejercicio 1
% Enunciado:
% Encuentre, el campo electrico en un cuadrado de 1 cm de lado.
% (a) Todas las cargas iguales positivas.
% (b) Todas las cargas iguales negativas.
% (c) Cargas intercaladas con positivos y negativos.
%
% Implementacion:
% Se calculan Ex y Ey para las cuatro cargas ubicadas en los vertices.

k = 1;
L = 1;
a = L / 2;

xa = -0.8:0.1:0.8;
ya = -0.8:0.1:0.8;
[x, y] = meshgrid(xa, ya);

xc = [-a, a, a, -a];
yc = [-a, -a, a, a];

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

figure('Name', 'L5 Ejercicio 1 - Campo electrico en cuadrado');

for caso = 1:size(casos, 1)
    q = casos(caso, :);
    [Ex, Ey] = campoElectrico(x, y, xc, yc, q, k);

    subplot(1, 3, caso);
    quiver(x, y, Ex, Ey, 2);
    hold on;
    dibujarCargas(xc, yc, q);
    plot([xc, xc(1)], [yc, yc(1)], 'k:');
    axis equal;
    axis([-0.9 0.9 -0.9 0.9]);
    grid on;
    xlabel('x');
    ylabel('y');
    title(titulos{caso});
    hold off;
end

function [Ex, Ey] = campoElectrico(x, y, xc, yc, q, k)
    Ex = zeros(size(x));
    Ey = zeros(size(y));

    for i = 1:numel(q)
        dx = x - xc(i);
        dy = y - yc(i);
        r2 = dx.^2 + dy.^2;
        r3 = r2 .* sqrt(r2);
        r3(r3 < eps) = NaN;

        Ex = Ex + k * q(i) .* dx ./ r3;
        Ey = Ey + k * q(i) .* dy ./ r3;
    end

    Ex(~isfinite(Ex)) = 0;
    Ey(~isfinite(Ey)) = 0;
end

function dibujarCargas(xc, yc, q)
    positivas = q > 0;
    negativas = q < 0;

    plot(xc(positivas), yc(positivas), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 7);
    plot(xc(negativas), yc(negativas), 'bo', 'MarkerFaceColor', 'b', 'MarkerSize', 7);
end
