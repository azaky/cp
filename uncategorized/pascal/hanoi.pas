var
  n:integer;
  f:text;

procedure move(n,awal,akhir,sisa:integer);
  begin
    if n=1 then writeln(f,'move ''',n,''' from ',awal,' to ',akhir)
      else
        begin
          move(n-1,awal,sisa,akhir);
          writeln(f,'move ''',n,''' from ',awal,' to ',akhir);
          move(n-1,sisa,akhir,awal);
        end;
  end;

begin
  assign(f,'tes.out');
  rewrite(f);
  readln(n);
  move(n,1,3,2);
  close(f);
end.
