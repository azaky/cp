type
  arr=array[1..1001] of longint;

var
  t,kasus,n,u,k,b,i,j,q,z,h,temp,max,init:longint;
  m,pos:array[1..8,1..10] of longint;
  x:array[1..8,1..10] of arr;
  p,take,best:array[1..8] of longint;
  gr:array[0..2500] of longint;
  used:array[1..10] of boolean;
  bar:string;
  ch:char;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a)
      else exit(b);
  end;

procedure qsort(var a:arr; n:longint);
  procedure sort(l,r:longint);
    var
      i,j,mid,temp:longint;
      
    begin
      i:=l; j:=r;
      mid:=a[(l+r) div 2];
      repeat
        while a[i]<mid do inc(i);
        while a[j]>mid do dec(j);
        if i<=j then
          begin
            temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
            inc(i); dec(j);
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;
    
  begin
    sort(1,n);
  end;

procedure add(j:integer);
  begin
    inc(m[j][k]);
    x[j][k][m[j][k]]:=h;
  end;

function index(u:longint):longint;
  var
    l,r,mid:longint;
    
  begin
    l:=0; r:=max;
    if u>=gr[r] then exit(r);
    repeat
      mid:=(l+r) div 2;
      if u<gr[mid] then r:=mid
        else l:=mid;
    until r-l=1;
    exit(l);
  end;

begin
{
assign(input,'rakit.txt'); reset(input);
assign(output,'rakit.out'); rewrite(output);
}
  readln(t);
  for kasus:=1 to t do
    begin
      writeln('Kasus ',kasus);
      fillchar(m,sizeof(m),0);
      fillchar(gr,sizeof(gr),255);
      
      readln(n);
      
      //indices for component:
      //1 = cpu
      //2 = ram
      //3 = crt
      //4 = lcd
      //5 = hdd-ide
      //6 = kabel-ide
      //7 = ssd-sata
      //8 = kabel-sata
      
      for k:=1 to n do
        begin
          readln(b);
          for i:=1 to b do
            begin
              bar:='';
              
              repeat
                read(ch);
                if ch<>' ' then bar:=bar+ch;
              until ch=' ';
              readln(h);
              
              if bar = 'cpu' then add(1)
              else if bar = 'ram' then add(2)
              else if bar = 'crt' then add(3)
              else if bar = 'lcd' then add(4)
              else if bar = 'hdd-ide' then add(5)
              else if bar = 'kabel-ide' then add(6)
              else if bar = 'ssd-sata' then add(7)
              else if bar = 'kabel-sata' then add(8);
              
              for j:=1 to 8 do
                if m[j][k]>0 then qsort(x[j][k],m[j][k]);
              
            end;
        end;
      
      fillchar(used,sizeof(used),false);
      fillchar(p,sizeof(p),0);
      init:=0;
      gr[0]:=0;
      
      for k:=1 to n do
        for i:=1 to 8 do
          begin
            p[i]:=p[i]+m[i][k];
            pos[i][k]:=1;
          end;
      
      max:=min(p[1],p[2]);
      max:=min(max,p[3]+p[4]);
      max:=min(max,min(p[5],p[6])+min(p[7],p[8]));
      
      for b:=1 to max do
        begin
          fillchar(best,sizeof(best),255);
          
          for k:=1 to n do
            for i:=1 to 8 do
              if (pos[i][k]<=m[i][k]) then
                begin
                  temp:=x[i][k][pos[i][k]];
                  if not used[k] then temp:=temp+10;
                  if (best[i]<0) or (best[i]>temp) then
                    begin
                      take[i]:=k;
                      best[i]:=temp;
                    end;
                end;
          
          //buy cpu and ram
          for i:=1 to 2 do
            begin
              inc(init,best[i]);
              inc(pos[i][take[i]]);
              if not used[take[i]] then used[take[i]]:=true;
            end;
          
          //buy monitor
          if best[3]<best[4] then i:=3
            else i:=4;
          
          inc(init,best[i]);
          inc(pos[i][take[i]]);
          if not used[take[i]] then used[take[i]]:=true;
          
          //buy hard disk
          if ((best[5]>0) and (best[6]>0)) and (((best[7]<0) or (best[8]<0)) or (best[5]+best[6]<best[7]+best[8])) then k:=5
            else k:=7;
          
          for i:=k to k+1 do
            begin
              inc(init,best[i]);
              inc(pos[i][take[i]]);
              if not used[take[i]] then used[take[i]]:=true;
            end;
        
          gr[b]:=init;
          writeln(gr[b]);
          
        end;
      
      readln(q);
      for i:=1 to q do
        begin
          readln(u);
          z:=index(u);
          
          writeln(z,' buah komputer sisa US$ ',u-gr[z]);
        end;
    end;
{
close(input);
close(output);
}
end.

