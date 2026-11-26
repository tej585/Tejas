import { Check, Home, RotateCcw, Trophy, X } from 'lucide-react'
import { Button } from '@/components/ui/button'
import type { Category, Question } from '@/lib/quiz-data'

export type AnswerRecord = {
  question: Question
  selected: number | null
  correct: boolean
  points: number
}

type Props = {
  category: Category
  answers: AnswerRecord[]
  onRetry: () => void
  onHome: () => void
}

function verdict(pct: number) {
  if (pct === 100) return { title: 'Flawless!', note: 'A perfect run. Nothing gets past you.' }
  if (pct >= 75) return { title: 'Impressive!', note: 'You clearly know your stuff.' }
  if (pct >= 50) return { title: 'Solid effort', note: 'Good foundation — one more round?' }
  return { title: 'Keep going', note: 'Every miss is a new fact learned.' }
}

export function QuizResults({ category, answers, onRetry, onHome }: Props) {
  const correctCount = answers.filter((a) => a.correct).length
  const total = answers.length
  const pct = Math.round((correctCount / total) * 100)
  const score = answers.reduce((sum, a) => sum + a.points, 0)
  const { title, note } = verdict(pct)

  return (
    <div className="mx-auto flex w-full max-w-3xl flex-col gap-10 px-4 py-12 md:py-16">
      <section className="flex flex-col items-center gap-6 rounded-3xl border-2 border-foreground bg-card p-8 text-center shadow-[6px_6px_0_0_var(--foreground)] animate-in fade-in zoom-in-95 duration-500 md:p-12">
        <span className="flex size-16 items-center justify-center rounded-2xl border-2 border-foreground bg-highlight">
          <Trophy className="size-8" aria-hidden="true" />
        </span>
        <div className="flex flex-col gap-2">
          <p className="text-sm font-semibold uppercase tracking-widest text-muted-foreground">{category.name}</p>
          <h1 className="font-display text-5xl font-bold md:text-6xl">{title}</h1>
          <p className="text-lg text-muted-foreground">{note}</p>
        </div>
        <dl className="grid w-full max-w-md grid-cols-3 gap-3">
          <Stat label="Correct" value={`${correctCount}/${total}`} />
          <Stat label="Accuracy" value={`${pct}%`} />
          <Stat label="Points" value={score.toLocaleString()} highlight />
        </dl>
        <div className="flex flex-wrap justify-center gap-3">
          <Button size="lg" onClick={onRetry} className="h-12 gap-2 rounded-xl px-6 text-base">
            <RotateCcw className="size-4" aria-hidden="true" />
            {'Play again'}
          </Button>
          <Button size="lg" variant="outline" onClick={onHome} className="h-12 gap-2 rounded-xl border-2 border-foreground px-6 text-base">
            <Home className="size-4" aria-hidden="true" />
            {'New category'}
          </Button>
        </div>
      </section>

      <section aria-labelledby="review-heading" className="flex flex-col gap-4">
        <h2 id="review-heading" className="font-display text-2xl font-bold">
          {'Review your answers'}
        </h2>
        <ol className="flex flex-col gap-3">
          {answers.map((a, i) => (
            <li key={a.question.id} className="flex gap-4 rounded-xl border-2 border-foreground/15 bg-card p-4">
              <span
                className={`flex size-8 shrink-0 items-center justify-center rounded-lg ${
                  a.correct ? 'bg-success text-success-foreground' : 'bg-destructive text-white'
                }`}
              >
                {a.correct ? <Check className="size-4" aria-label="Correct" /> : <X className="size-4" aria-label="Incorrect" />}
              </span>
              <div className="flex flex-1 flex-col gap-1">
                <p className="font-semibold">{`${i + 1}. ${a.question.prompt}`}</p>
                <p className="text-sm text-muted-foreground">
                  {'Answer: '}
                  <span className="font-medium text-foreground">{a.question.options[a.question.answer]}</span>
                  {!a.correct && (
                    <>
                      {' · You: '}
                      <span className="font-medium text-foreground">
                        {a.selected === null ? 'No answer' : a.question.options[a.selected]}
                      </span>
                    </>
                  )}
                </p>
              </div>
              <span className="shrink-0 font-display font-bold tabular-nums">{`+${a.points}`}</span>
            </li>
          ))}
        </ol>
      </section>
    </div>
  )
}

function Stat({ label, value, highlight }: { label: string; value: string; highlight?: boolean }) {
  return (
    <div
      className={`flex flex-col gap-1 rounded-xl border-2 border-foreground p-3 ${
        highlight ? 'bg-primary text-primary-foreground' : 'bg-background'
      }`}
    >
      <dt className="text-xs font-semibold uppercase tracking-wider opacity-80">{label}</dt>
      <dd className="font-display text-2xl font-bold tabular-nums">{value}</dd>
    </div>
  )
}
