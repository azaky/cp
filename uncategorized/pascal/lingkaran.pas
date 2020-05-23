program lingkaran;

uses
  crt;

const
  Pi=3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068;

procedure lingkaran;
  var
    r:real;
    n:integer;
    input:string;

  begin
    clrscr;
    write('Masukkan jari-jari : ');
    readln(r);
    write('Pembulatan sampai ... digit di belakang koma (0 <= n <= 15) : ');
    readln(n);
    writeln('Luas lingkaran = ',(r*r*Pi):1:n);
    writeln('Keliling lingkaran = ',(2*r*Pi):1:n);
    write('Coba lagi? (ya/tidak) : ');
    readln(input);
    if input='ya' then lingkaran else exit;
  end;

begin
  lingkaran;
end.
