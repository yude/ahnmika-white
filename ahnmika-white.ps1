try
{
    $count=0
  while($true)
  {
  $colors = Get-Random -Minimum 100 -Maximum 1000
  Write-Host ("白って${colors}色あんねん")
  $count++
  }
}
finally
{
  Write-Host "${count}人のアンミカ"
}