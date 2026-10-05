type Props = {
  timeLeft: number
  total: number
  paused: boolean
}

export function TimerBar({ timeLeft, total, paused }: Props) {
  const pct = Math.max(0, (timeLeft / total) * 100)
  const urgent = timeLeft <= 5 && !paused

  return (
    <div
      role="progressbar"
      aria-label="Time remaining"
      aria-valuemin={0}
      aria-valuemax={total}
      aria-valuenow={timeLeft}
      className="h-1.5 w-full overflow-hidden rounded-full bg-foreground/10"
    >
      <div
        className={`h-full rounded-full transition-[width] duration-1000 ease-linear ${
          urgent ? 'bg-destructive' : 'bg-primary'
        }`}
        style={{ width: `${pct}%` }}
      />
    </div>
  )
}
