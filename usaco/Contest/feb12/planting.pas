{
ID: a_zaky01
PROG: planting
LANG: PASCAL
}

type
  rectangle=record
    llx,lly,urx,ury:int64;
    col:integer;
  end;

var
  n,i:integer;
  ans:int64;
  rect:array[0..1111] of rectangle;
  area:array[0..1111] of int64;

procedure calc(rect0:rectangle; cover:integer);
  var
    temp:rectangle;

  begin
    while (cover<=n) and  ((rect0.llx>=rect[cover].urx)
                        or (rect0.urx<=rect[cover].llx)
                        or (rect0.lly>=rect[cover].ury)
                        or (rect0.ury<=rect[cover].lly)) do inc(cover);
    if cover>n then inc(area[rect0.col],(rect0.urx-rect0.llx)*(rect0.ury-rect0.lly))
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
  assign(input,'planting.in'); reset(input);
  assign(output,'planting.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
    with rect[i] do
      readln(llx,ury,urx,lly);
  for i:=1 to n do rect[i].col:=i;
  for i:=1 to n do calc(rect[i],i+1);
  ans:=0;
  for i:=1 to n do ans:=ans+area[i];
  writeln(ans);
  close(input); close(output);
end.
