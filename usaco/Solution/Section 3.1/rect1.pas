{
ID: a_zaky01
PROG: rect1
LANG: PASCAL
}

type
  rectangle=record
    llx,lly,urx,ury,col:integer;
  end;

var
  n,x0,y0,i:integer;
  rect:array[0..1000] of rectangle;
  fin,fout:text;

procedure calc(rect0:rectangle; cover:integer);
  var
    temp:rectangle;

  begin
    while (cover<=n) and  ((rect0.llx>=rect[cover].urx)
                        or (rect0.urx<=rect[cover].llx)
                        or (rect0.lly>=rect[cover].ury)
                        or (rect0.ury<=rect[cover].lly)) do inc(cover);
    if cover>n then inc(area,(rect0.urx-rect0.llx)*(rect0.ury-rect0.lly))
      else
        begin
          if rect0.ury>rect[cover].ury then
            begin
              temp:=rect0;
              temp.lly:=rect[cover].ury;
              rect0.ury:=temp.lly;
              calc(temp,cover+1);
            end;
          if rect0.lly<rect[cover].lly then
            begin
              temp:=rect0;
              temp.ury:=rect[cover].lly;
              rect0.lly:=temp.ury;
              calc(temp,cover+1);
            end;
          if rect0.urx>rect[cover].urx then
            begin
              temp:=rect0;
              temp.llx:=rect[cover].urx;
              calc(temp,cover+1);
            end;
          if rect0.llx<rect[cover].llx then
            begin
              temp:=rect0;
              temp.urx:=rect[cover].llx;
              calc(temp,cover+1);
            end;
        end;
  end;

begin
  assign(fin,'rect1.in');
  assign(fout,'rect1.out');
  reset(fin);
  rewrite(fout);
  readln(fin,x0,y0,n);
  for i:=1 to n do
    with rect[i] do
      readln(fin,llx,lly,urx,ury,col);
  with rect[0] do
    begin
      llx:=0;
      lly:=0;
      urx:=x0;
      ury:=y0;
      col:=1;
    end;
  for i:=0 to n do calc(rect[i],i+1);
  for i:=1 to 2500 do
    if area[i]>0 then writeln(fout,i,' ',area[i]);
  close(fin);
  close(fout);
end.

