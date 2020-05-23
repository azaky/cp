{
ID: a_zaky01
PROG: window
LANG: PASCAL
}

type
  rectangle=record
    llx,lly,urx,ury,col:longint;
  end;

var
  k,z,size,i:longint;
  area:int64;
  trect:rectangle;
  task:string;
  ch:char;
  percent:extended;
  num:array[1..4] of longint;
  rect:array[0..63] of rectangle;
  val:array[chr(0)..chr(255)] of integer;
  show:array[0..63] of boolean;
  name:array[0..63] of char;
  pos:array[0..63] of integer;

procedure calc(rect0:rectangle; cover:integer);
  var
    temp:rectangle;

  begin
    while (cover<=size) and  ((rect0.llx>=rect[cover].urx)
                           or (rect0.urx<=rect[cover].llx)
                           or (rect0.lly>=rect[cover].ury)
                           or (rect0.ury<=rect[cover].lly)) do inc(cover);
    if cover>size then area:=area + (rect0.urx-rect0.llx)*(rect0.ury-rect0.lly)
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

procedure swap(var a,b:longint);
  var
    temp:longint;
  
  begin
    temp:=a;
    a:=b;
    b:=temp;
  end;

begin

  assign(input,'window.in');
  assign(output,'window.out');
  reset(input);
  rewrite(output);

  
  k:=0;
  for ch:='a' to 'z' do
    begin
      inc(k);
      val[ch]:=k;
    end;
  for ch:='A' to 'Z' do
    begin
      inc(k);
      val[ch]:=k;
    end;
  for ch:='0' to '9' do
    begin
      inc(k);
      val[ch]:=k;
    end;
  size:=0;
  
  while not eof do
    begin
      readln(task);
      case task[1] of
        'w': begin
               ch:=task[3];
               z:=0;
               fillchar(num,sizeof(num),0);
               for i:=4 to length(task) do
                 if task[i]=')' then break
                   else if task[i]=',' then inc(z)
                     else num[z]:=10*num[z]+ord(task[i])-ord('0');
               inc(size);
               with rect[size] do
                 begin
                   llx:=num[1];
                   lly:=num[2];
                   urx:=num[3];
                   ury:=num[4];
                   if llx>urx then swap(llx,urx);
                   if lly>ury then swap(lly,ury);
                 end;
               show[val[ch]]:=true;
               pos[val[ch]]:=size;
               name[size]:=ch;
             end;
        't': begin
               ch:=task[3];
               trect:=rect[pos[val[ch]]];
               for i:=pos[val[ch]] to size-1 do
                 begin
                   rect[i]:=rect[i+1];
                   name[i]:=name[i+1];
                   pos[val[name[i]]]:=i;
                 end;
               rect[size]:=trect;
               pos[val[ch]]:=size;
               name[size]:=ch;
             end;
        'b': begin
               ch:=task[3];
               trect:=rect[pos[val[ch]]];
               for i:=pos[val[ch]] downto 2 do
                 begin
                   rect[i]:=rect[i-1];
                   name[i]:=name[i-1];
                   pos[val[name[i]]]:=i;
                 end;
               rect[1]:=trect;
               pos[val[ch]]:=1;
               name[1]:=ch;
             end;
        'd': begin
               ch:=task[3];
               dec(size);
               for i:=pos[val[ch]] to size do
                 begin
                   rect[i]:=rect[i+1];
                   name[i]:=name[i+1];
                   pos[val[name[i]]]:=i;
                 end;
               show[val[ch]]:=false;
             end;
        's': begin
               ch:=task[3];
               area:=0;
               calc(rect[pos[val[ch]]],pos[val[ch]]+1);
               with rect[pos[val[ch]]] do percent:=area*100/((urx-llx)*(ury-lly));
               writeln(percent:0:3);
             end;
      end;
        
    end;
  

  close(input);
  close(output);

end.

