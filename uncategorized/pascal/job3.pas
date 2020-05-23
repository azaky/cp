{
ID: a_zaky01
PROG: job
LANG: PASCAL
}

uses
  math;

const
  maxtime=620;

type
  machine=record
    m:longint;
    time,used:array[1..30] of longint;
  end;
  donex=array[1..1000] of longint;

var
  n,i,j,k,ansa,ansb,temp1,temp2,best:longint;
  a,b:machine;
  donea,doneb:donex;
  fin,fout:text;

procedure qsort(var a:machine);
  procedure sort(l,r:longint);
    var
      i,j,mid,temp:longint;

    begin
      with a do
        begin
          i:=l;
          j:=r;
          mid:=time[(l+r) div 2];
          repeat
            while time[i]<mid do inc(i);
            while time[j]>mid do dec(j);
            if i<=j then
              begin
                temp:=time[i];
                time[i]:=time[j];
                time[j]:=temp;
                inc(i);
                dec(j);
              end;
          until i>j;
          if l<j then sort(l,j);
          if i<r then sort(i,r);
        end;
    end;

  begin
    sort(1,a.m);
  end;

procedure dsort(var done:donex);
  procedure sort(l,r:longint);
    var
      i,j,temp,mid:longint;

    begin
      i:=l;
      j:=r;
      mid:=done[(l+r) div 2];
      repeat
        while done[i]<mid do inc(i);
        while done[j]>mid do dec(j);
        if i<=j then
          begin
            temp:=done[i];
            done[i]:=done[j];
            done[j]:=temp;
            inc(i);
            dec(j);
          end;
      until i>j;
      if l<j then sort(l,j);
      if i<r then sort(i,r);
    end;

  begin
    sort(1,n);
  end;
{
procedure joba(a:machine; k,total:integer);
  var
    i,j,r:longint;

  begin
    with a do
      if k>n then
        begin
          ansa:=total;
          r:=0;
          for i:=1 to m do
            for j:=1 to (used[i] div time[i]) do
              begin
                inc(r);
                done[r]:=j*time[i];
              end;
        end
      else
        for i:=1 to m do
          begin
            inc(used[i],time[i]);
            if max(total,used[i])<ansa then joba(a,k+1,max(total,used[i]));
            dec(used[i],time[i]);
          end;
  end;

procedure jobb(b:machine; k,total:integer);
  var
    temp,i:longint;

  begin
    if k>n then ansb:=total
      else with b do
        for i:=1 to m do
          begin
            temp:=max(done[k],used[i])+time[i]-used[i];
            inc(used[i],temp);
            if max(total,used[i])<ansb then jobb(b,k+1,max(total,used[i]));
            dec(used[i],temp);
          end;
  end;
}

begin
  assign(fin,'job.in');
  assign(fout,'job.out');
  reset(fin);
  rewrite(fout);
  read(fin,n,a.m,b.m);
  for i:=1 to a.m do read(fin,a.time[i]);
  for i:=1 to b.m do read(fin,b.time[i]);

  qsort(a);
  qsort(b);

  ansa:=0;
  ansb:=0;
  with a do
    for i:=1 to n do
      begin
        best:=maxtime;
        for j:=1 to m do
          if used[j]+time[j]<best then
            begin
              best:=used[j]+time[j];
              k:=j;
            end;
        donea[i]:=best;
        inc(used[k],time[k]);
      end;

  with b do
    for i:=1 to n do
      begin
        best:=maxtime;
        for j:=1 to m do
          if used[j]+time[j]<best then
            begin
              best:=used[j]+time[j];
              k:=j;
            end;
        doneb[i]:=best;
        inc(used[k],time[k]);
      end;

{
    begin
      for i:=1 to n do begin
        for j:=m downto 1 do
          if j=1 then used[j]:=max(used[j],done[i])+time[j]
            else
              begin
                temp1:=max(used[j],done[i])+time[j];
                temp2:=max(used[j-1],done[i])+time[j-1];
                if temp1<=temp2 then
                  begin
                    used[j]:=temp1;
                    break;
                  end;
              end;
        for j:=1 to m do write(used[j],' ');
        writeln(done[i]);
        end;
      for i:=1 to m do ansb:=max(ansb,used[i]);
    end;
}

  dsort(donea);
  dsort(doneb);


  for i:=1 to n-1 do write(fout,donea[i]:2,' ');
  writeln(fout,donea[n]:2);
  for i:=1 to n-1 do write(fout,doneb[i]:2,' ');
  writeln(fout,doneb[n]:2);


  for i:=1 to n do
    begin
      ansa:=max(ansa,donea[i]);
      ansb:=max(ansb,donea[i]+doneb[n-i+1]);
    end;

  writeln(fout,ansa,' ',ansb);
  close(fin);
  close(fout);
end.
