clear;
close all;
clc;

% Laboratorio 5 - Ejercicio 3
% Enunciado:
% Encuentre, el campo electrico en un hexagono de radio 1 cm.
% (a) Todas las cargas iguales positivas.
% (b) Todas las cargas iguales negativas.
% (c) Cargas intercaladas con positivos y negativos.
%
% Implementacion:
% Se calculan Ex y Ey para seis cargas en los vertices del hexagono.

k = 1;
R = 1;

xa = -2:0.15:2;
ya = -2:0.15:2;
[x, y] = meshgrid(xa, ya);

angulos = 0:60:300;
xc = R * cosd(angulos);
yc = R * sind(angulos);

casos = [
     1,  1,  1,  1,  1,  1;
    -1, -1, -1, -1, -1, -1;
     1, -1,  1, -1,  1, -1
];

titulos = {
    '(a) Todas las cargas positivas'
    '(b) Todas las cargas negativas'
    '(c) Cargas intercaladas'
};

figure('Name', 'L5 Ejercicio 3 - Campo electrico en hexagono');

for caso = 1:size(casos, 1)
    q = casos(caso, :);
    [Ex, Ey] = campoElectrico(x, y, xc, yc, q, k);

    subplot(1, 3, caso);
    quiver(x, y, Ex, Ey, 2);
    hold on;
    dibujarCargas(xc, yc, q);
    plot([xc, xc(1)], [yc, yc(1)], 'k:');
    axis equal;
    axis([-2 2 -2 2]);
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
