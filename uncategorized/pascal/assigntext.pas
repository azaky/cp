unit assigntext;

interface

procedure assignfiles;
procedure closefiles;

implementation

var
  fin,fout:text;

procedure assignfiles;
  begin
    assign(fin,'text.txt'); reset(fin);
    assign(fout,'text.out'); rewrite(fout);
  end;

procedure closefiles;
  begin
    close(fin);
    close(fout)
  end;

end.
